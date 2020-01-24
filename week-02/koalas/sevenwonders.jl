function countCards()
    t, c, g = 0, 0, 0
    score = 0

    i = readline()

    for char in i
        if char == 'T'
            t += 1
        elseif char == 'C'
            c += 1
        elseif char == 'G'
            g += 1
        end
    end

    score += t^2 + c^2 + g^2

    times = 0
    while t != 0 && c != 0 && g != 0
        t -= 1
        c -= 1
        g -= 1
        times += 1
    end

    score += times*7

    return score
end

print(countCards())