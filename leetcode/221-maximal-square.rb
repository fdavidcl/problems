#!/usr/bin/env

# https://leetcode.com/problems/maximal-square/

def triangle left, right, up, down
  down * (1 + [left, right, up].min)
end

def at m, i, j
  return 0 if i < 0 || j < 0
  m[i][j].to_i
rescue NoMethodError
  0
end

# @param {String[][]} matrix
# @return {Integer}
def maximal_square(matrix)
  return 0 if matrix.empty?
  matrix.each { |row| row.map! &:to_i }

  matrix.each_with_index do |row, i|
    row.map!.each_with_index do |e, j|
      triangle (at matrix, i-1, j), (at matrix, i, j-1), (at matrix, i-1, j-1), e
    end
  end
  
  matrix.map(&:max).max**2
end
