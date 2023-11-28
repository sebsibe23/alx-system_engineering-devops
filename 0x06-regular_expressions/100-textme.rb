#!/usr/bin/env ruby
# Function: main
# Parameters: ARGV[0] - The first command line argument
# Return: None
# Description: script takes an argument from
# the command line and prints
# a parts of the argument that match a specific pattern.
# a pattern is looking for strings that are in
# the format "[from:(...)] [to:(...)] [flags:(...)]".

puts ARGV[0].scan(/\[from:(.*?)\] \[to:(.*?)\] \[flags:(.*?)\]/).join(",")
