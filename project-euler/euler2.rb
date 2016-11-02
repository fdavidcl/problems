def digits a
  dig = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
  while a > 0
    dig[a % 10] += 1
    a /= 10
  end
  dig
end

def same_digits a
  d = digits(a)
  (2 .. 6).all? { |i| d == digits(i * a) }
end

num = 1
loop do
  if same_digits num
    break
  else
    num += 1
  end
end

puts num
