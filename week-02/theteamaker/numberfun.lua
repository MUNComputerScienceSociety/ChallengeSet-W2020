lines = {}

for line in io.lines() do
    table.insert(lines, line)
end

iteration_amt = lines[1]

function is_possible(t)
    possibility = nil
    local current_number = 0

    local outcomes = {}

    table.insert(outcomes, t[1] + t[2])
    table.insert(outcomes, t[1] * t[2])

    table.insert(outcomes, t[1] - t[2])
    table.insert(outcomes, t[2] - t[1])
    
    table.insert(outcomes, t[1] / t[2])
    table.insert(outcomes, t[2] / t[1])

    for k, v in pairs(outcomes) do
        if v == tonumber(t[3])
        then
            possibility = true
            break
        end
    end

    return possibility
end

for i = 1, iteration_amt, 1 do
    local current = lines[i + 1]
    
    numbers = {}
    current_number = ""

    for i = 1, string.len(current), 1 do
        local byte = string.byte(current, i)
        local character = string.char(byte)

        if character ~= " "
        then
            current_number = current_number .. character
        
        elseif character == " "
        then
            table.insert(numbers, current_number)
            current_number = ""
        end
    
        -- if it's the last character of the string, append regardless
        if i == string.len(current)
        then
            table.insert(numbers, current_number)
            current_number = current_number
        end
    end

    possibility = is_possible(numbers)

    if possibility == true
    then
        io.write("Possible\n")

    elseif possibility == nil
    then
        io.write("Impossible\n")
    end
end