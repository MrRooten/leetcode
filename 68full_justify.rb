# @param {String[]} words
# @param {Integer} max_width
# @return {String[]}
def full_justify(words, max_width)
    $l = words.size
    $i = 0
    $j = 1
    $length = 0
    $ans = Array.new
    while $i < $l do
        $j = 0
        while $i+$j < $length do
            $str = words[$i,$j].join(" ")
            if $str.size >= max_width
                break
            end
            $j += 1
        end

        if $str.size == max_width do
            $ans.push $str
            $i = $i + $j + 1
            next
        end

        if $str.size > max_width do
            $j -= 1
            $n_space = max_width - words[$i,$j].join("").size
            $n_inners = $j - 1
            if $n_space % $n_inners == 0
                $ans.push words[$i,$j].join(" "*($n_space / $n_inners))
                next
            else
                $_n_space = $n_space + ($n_inners-($n_space % $n_inners))
                $str = words[$i,$j-1].join(" "*($_n_space / $n_inners))
                $str += " "*($n_space % $n_inners) + words[$j]
                ans.push $str
            end
        end
    end

    return $ans
end

full_justify(["abc"],3);