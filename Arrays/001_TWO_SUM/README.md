
# LeetCode 1 - Two Sum

## Problem
Given an array of integers and a target, return the indices of
the two numbers that add up to the target.

## Approach 1: Brute Force

Check every possible pair.

**Time:** O(n²)  
**Space:** O(1)

## Approach 2: Hash Map

Store previously visited numbers and check whether the required
complement already exists.

**Time:** O(n)  
**Space:** O(n)

## What I Learned

The brute-force approach is simple, but using a hash map reduces
the time complexity from O(n²) to O(n).
