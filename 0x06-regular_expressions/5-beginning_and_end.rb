#!/usr/bin/env ruby
# Function: main
# Parameters: ARGV[0] - the string passed as a command line argument
# Returns: None. Prints to stdout.
# Description: This script scans the input
# string for occurrences of the pattern "^h.n$" and prints them.

puts ARGV[0].scan(/^h.n$/).join
