#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Counters
TESTS_PASSED=0
TESTS_FAILED=0

# Program path
PROGRAM="../sed_is_for_losers"

# Test function
run_test() {
    local test_name="$1"
    local input_file="$2"
    local s1="$3"
    local s2="$4"
    local expected="$5"

    echo -n "Test: $test_name... "

    # Run program
    $PROGRAM "$input_file" "$s1" "$s2" > /dev/null 2>&1

    # Check if .replace file was created
    if [ ! -f "${input_file}.replace" ]; then
        echo -e "${RED}FAILED${NC} (no output file created)"
        ((TESTS_FAILED++))
        return 1
    fi

    # Compare result
    local result=$(cat "${input_file}.replace")
    if [ "$result" == "$expected" ]; then
        echo -e "${GREEN}PASSED${NC}"
        ((TESTS_PASSED++))
        rm -f "${input_file}.replace"
        return 0
    else
        echo -e "${RED}FAILED${NC}"
        echo "  Expected: $expected"
        echo "  Got:      $result"
        ((TESTS_FAILED++))
        rm -f "${input_file}.replace"
        return 1
    fi
}

# Test error handling
test_error() {
    local test_name="$1"
    shift

    echo -n "Error test: $test_name... "

    $PROGRAM "$@" > /dev/null 2>&1
    local exit_code=$?

    if [ $exit_code -ne 0 ]; then
        echo -e "${GREEN}PASSED${NC}"
        ((TESTS_PASSED++))
        return 0
    else
        echo -e "${RED}FAILED${NC} (should have returned error)"
        ((TESTS_FAILED++))
        return 1
    fi
}

echo "========================================="
echo "   SED Replacement Program Tester"
echo "========================================="
echo ""

# Check if program exists
if [ ! -f "$PROGRAM" ]; then
    echo -e "${RED}Error: Program '$PROGRAM' not found${NC}"
    echo "Please compile your program first (make)"
    exit 1
fi

# Create test files
echo "Creating test files..."

# Test file 1: Simple replacement
echo "Hello World" > test1.txt

# Test file 2: Multiple occurrences
echo "foo bar foo baz foo" > test2.txt

# Test file 3: Multi-line
cat > test3.txt << EOF
First line with test
Second line with test
Third line without it
EOF

# Test file 4: Empty file
touch test4.txt

# Test file 5: Special characters
echo "C++ is great. C++ rocks!" > test5.txt

# Test file 6: Overlapping patterns
echo "aaaa" > test6.txt

# Test file 7: No match
echo "Hello World" > test7.txt

echo ""
echo "Running tests..."
echo ""

# Basic tests
run_test "Simple replacement" "test1.txt" "World" "Universe" "Hello Universe"
run_test "Multiple occurrences" "test2.txt" "foo" "FOO" "FOO bar FOO baz FOO"
run_test "Multi-line replacement" "test3.txt" "test" "TEST" "First line with TEST
Second line with TEST
Third line without it"
run_test "Empty file" "test4.txt" "anything" "something" ""
run_test "Special characters" "test5.txt" "C++" "Rust" "Rust is great. Rust rocks!"
run_test "Overlapping patterns" "test6.txt" "aa" "b" "bb"
run_test "No match found" "test7.txt" "foo" "bar" "Hello World"
run_test "Replace with empty string" "test1.txt" "World" "" "Hello "
run_test "Replace entire line" "test1.txt" "Hello World" "Goodbye" "Goodbye"

# Edge cases
echo "one two three" > test_edge.txt
run_test "Replace with longer string" "test_edge.txt" "two" "LONGER" "one LONGER three"
run_test "Replace with shorter string" "test_edge.txt" "three" "3" "one two 3"

# Error handling tests
echo ""
echo "Testing error handling..."
echo ""

test_error "No arguments"
test_error "Too few arguments" "file.txt" "s1"
test_error "Too many arguments" "file.txt" "s1" "s2" "extra"
test_error "Non-existent file" "nonexistent.txt" "s1" "s2"
test_error "Empty s1" "test1.txt" "" "s2"

# Cleanup test files
echo ""
echo "Cleaning up test files..."
rm -f test*.txt test_edge.txt *.replace

# Summary
echo ""
echo "========================================="
echo "   Test Results"
echo "========================================="
echo -e "${GREEN}Passed: $TESTS_PASSED${NC}"
echo -e "${RED}Failed: $TESTS_FAILED${NC}"
echo "========================================="

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed!${NC}"
    exit 1
fi
