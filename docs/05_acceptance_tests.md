
# Acceptance Tests - Two Sum

## Overview
Tests for the Two Sum algorithm that finds two numbers in an array that sum to a target value.

## Test Cases

### TC-001: Valid pair exists
**Given:** Array `[2, 7, 11, 15]`, target `9`
**When:** Finding two numbers that sum to target
**Then:** Return indices `[0, 1]`

### TC-002: Multiple pairs, return first valid
**Given:** Array `[3, 3]`, target `6`
**When:** Finding two numbers that sum to target
**Then:** Return indices `[0, 1]`

### TC-003: No valid pair exists
**Given:** Array `[1, 2, 3]`, target `10`
**When:** Finding two numbers that sum to target
**Then:** Return empty result or null

### TC-004: Negative numbers
**Given:** Array `[-1, -2, -3, 5]`, target `2`
**When:** Finding two numbers that sum to target
**Then:** Return indices `[2, 3]` (for `-3 + 5 = 2`)

### TC-005: Empty array
**Given:** Array `[]`
**When:** Finding two numbers
**Then:** Return empty result or error

## Acceptance Criteria
- ✓ Function handles valid input correctly
- ✓ Function handles edge cases (empty, no match)
- ✓ Function works with negative numbers
- ✓ Function returns correct indices, not values
