
#This is [very for i in range(1000000000000000000000000000000000000)] suck version of is_scramble,if anyone see this and try to copy that to your code,YOU BETTER NOT TO DO THAT.
#It's an overtime version,I actually hava a better way(faster way),But I am too lazy to write that code.
#I don't think I gonnon write that down,just picture it.
# @param {String} s1
# @param {String} s2
# @return {Boolean}
def is_scramble(s1, s2)
    if s1.size == 0
        return true
    end
    tmp1 = s1.split("").sort
    tmp2 = s2.split("").sort
    if tmp1 != tmp2 
        return false
    end
    if s1.size <= 3
        if tmp1 == tmp2
            return true
        end
    end


    l1 = s1.size
    l2 = s2.size
    (1..s1.size-1).each do |i|
        if is_scramble(s1[0,i],s2[0,i]) and is_scramble(s1[i,l1-i],s2[i,l2-i])
            return true
        elsif is_scramble(s1[0,i],s2[-i,i]) and is_scramble(s1[i-l1,l1-i],s2[0,l2-i])
            return true
        else
            next
        end
    end

    return false
end

a,b = "eebaacbcbcadaaedceaaacadccd","eadcaacabaddaceacbceaabeccd"

p is_scramble(a,b)