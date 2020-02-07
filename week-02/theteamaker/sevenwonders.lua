input = io.read()

letters = {}

letters["T"] = 0
letters["G"] = 0
letters["C"] = 0

-- A for loop to iterate through the string and log the amount of occurrences of a given card type.

for i = string.len(input), 1, -1 do
    local byte = string.byte(input, i)
    local character = string.char(byte)

    for k, v in pairs(letters) do
        if(k == character)
        then
            letters[k] = letters[k] + 1
        end
    end
end

-- Logic for deducing the amount of complete sets in the given hand.

amounts = {}
iter_amt = 1
for k, v in pairs(letters) do
    amounts[iter_amt] = v
    iter_amt = iter_amt + 1
end

sets = math.min(unpack(amounts))

total = 0
-- Adding all pairs 
for k, v in pairs(letters) do
    total = total + math.pow(v, 2)
end

-- Adding the bonus points for each set
total = total + (7 * sets)

io.write(math.floor(total))