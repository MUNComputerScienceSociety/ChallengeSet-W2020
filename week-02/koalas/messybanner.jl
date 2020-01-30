function messy()
    for input in readlines()
        if !(length(input) < 7)
            if occursin(r"([A-Z])", string(input[1]))
                if occursin(r"([A-Z])|\s", string(input[1:3]))
                    if occursin(r"([0-9])", string(input[4:7]))
                        if length(input) == 8 && occursin(r"([A-Z])", string(input[8]))
                            print("Y\n")
                            continue
                        elseif length(input) == 7
                            print("Y\n")
                            continue
                        end
                    end
                end
            end
        end
        print("N\n")
    end
end

messy()
