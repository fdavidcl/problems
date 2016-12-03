# https://leetcode.com/problems/longest-absolute-file-path/
# @param {String} input
# @return {Integer}
def length_longest_path(input)
    stack = []
    max = 0
    
    input.split("\n").each do |name|
        depth = name.count "\t"
        sname = name[depth ... name.length]
        stack = stack[0 ... depth]
        
        if sname.include? "."
            max = [(stack.last || 0) + sname.length, max].max
        else
            stack << (stack.last || 0) + sname.length + 1
        end
    end
    
    max
end
