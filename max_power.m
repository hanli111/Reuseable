function P = max_power(efficiency, dam_height, mass_flow)
    P = (efficiency * dam_height * mass_flow * 9.81) / 10^9;
end
