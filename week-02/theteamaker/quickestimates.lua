lines = {}

for line in io.lines() do
    table.insert(lines, line)
end

iteration_amt = lines[1]

for i = 1, iteration_amt, 1 do
    local current = lines[i + 1]
    local count = 0

    for i = 1, string.len(current), 1 do
        count = count + 1
    end

    io.write(count, "\n")
end