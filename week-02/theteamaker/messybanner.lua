lines = {}

for line in io.lines() do
    table.insert(lines, line)
end

for i, room in pairs(lines) do
    validity = true

    local str_table = {}

    for i = 1, #room do
        local byte = string.byte(room, i)
        local character = string.char(byte)

        table.insert(str_table, character)
    end

    -- conditions for each different character --
    
    for i = 1, 8, 1 do

        if i == 1 -- the first character must be an uppercase letter
        then
            if string.match(str_table[i], '%u') == nil
            then
                validity = false
                break
            end

        elseif i >= 2 and i <= 3 or i == 8
        then
            if string.match(str_table[i], '%u') == nil and str_table[i] ~= ' '
            then
                validity = false
                break
            end

        elseif i >= 4 and i <= 7
        then
            if string.match(str_table[i], '%d') == nil
            then
                validity = false
                break
            end
        end
    end

    if validity == true
    then
        io.write("Y\n")
    
    elseif validity == false
    then
        io.write("N\n")
    end
end