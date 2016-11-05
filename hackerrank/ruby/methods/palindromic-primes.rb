#!/usr/bin/env ruby
# https://www.hackerrank.com/challenges/ruby-lazy

# Define these methods inside builtin classes for greater readability
class String
  def palindrome?
    self == reverse
  end
end
class Integer
  def prime?
    (2..Math.sqrt(self)).none? { |d| self % d == 0 }
  end
end

# Defining an enumerator is easier than an infinite lazy array :P
palindromic = Enumerator.new do |yielder|
  prime = 2
  
  loop do
    yielder << prime
    prime += 1
    # Filter by palindromes first - way faster than checking primality
    prime += 1 until prime.to_s.palindrome? && prime.prime? 
  end
end

# Print first n palindromic primes
n = gets.strip.to_i
puts palindromic.first(n).to_s
