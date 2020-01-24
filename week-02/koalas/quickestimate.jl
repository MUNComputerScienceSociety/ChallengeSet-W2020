function estimate()
    n = parse(Int, readline())

    for i = 0:(n - 1)
        print(string(length(readline())) , "\n")
    end
end

estimate()