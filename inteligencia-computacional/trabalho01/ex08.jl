function combinações(xs::Any, k::Integer)
    if k == 0
        return [[]]
    elseif isempty(xs)
        return []
    end

    head = xs[1]
    tail = xs[2:end]
    
    add_head = [[head; c] for c in combinações(tail, k - 1)]
    add_tail = combinações(tail, k)
    
    return vcat(add_head, add_tail)
end

# exemplos
println(combinações([1, 2, 3, 4], 2))
println(combinações("abcdef", 4))
println(combinações([1, 2, 3, 4, 5, 6], 3))
