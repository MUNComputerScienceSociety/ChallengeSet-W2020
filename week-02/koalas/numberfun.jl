function possible()
    n = parse(Int,readline())

    for i = 0:(n - 1)
        s = split(readline())
        n1, n2, res = parse(Int, s[1]), parse(Int, s[2]), parse(Int, s[3])

        if n1 + n2 == res
            print("Possible\n")
            continue
        elseif abs(n1 - n2) == abs(res)
            print("Possible\n")
            continue
        elseif n1 * n2 == res
            print("Possible\n")
            continue
        elseif n1/n2 == res || n2/n1 == res
            print("Possible\n")
            continue
        else
            print("Impossible\n")
            continue
        end
    end
end

possible()