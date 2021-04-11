# @param {String} path
# @return {String}
def simplify_path(path)
    stack = []
    res_arr = []
    path.split(/\/+/) do |dir|
        if dir == ""
            next
        end

        stack << dir
    end

    stack.each do |dir|
        if dir == ".."
            if res_arr.size == 0
                next
            elsif
                res_arr.pop
                next
            end
        end

        if dir == "."
            next
        end

        res_arr << dir
    end
    
    '/'+res_arr.join('/')
end

p simplify_path("/home//foo/")