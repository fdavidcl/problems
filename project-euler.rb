# 1. Multples of 3 or 5
(1...1000).select{|e| (e%3)*(e%5) == 0}.inject(&:+)

# 2. Even Fibonacci numbers
even_fib = Enumerator.new do |yielder|
  a, b = 0, 1

  while a <= 4e6
    yielder << a

    a, b = b, a + b

    until a.even?
      a, b = b, a + b
    end
  end
end
even_fib.inject &:+

# 3. Largest prime factor
primes = Enumerator.new do |yielder|
  n = 2

  loop do
    yielder << n

    is_prime = false
    until is_prime
      n += 1

      is_prime = (2 .. Math.sqrt(n)).none?{|i| n % i == 0}
    end
  end
end

number = 600851475143
last_factor = 1

while number > 1
  i = primes.next

  if number % i == 0
    number /= i
    last_factor = i
  end
end

puts last_factor

# 51. Prime digit replacements
