function volume = reservoir_volume(water_height)
    load('project1_data.mat');
    [X, Y] = meshgrid(x, y);
    water = water_height * ones(size(valley));

    water(valley > water_height) = NaN;
    line = -0.8 * X + 2200;
    water(Y < line) = NaN;

    depth = water - valley;
    depth(isnan(depth)) = 0;

    %Delta X and Delta Y
    dx = x(2) - x(1);
    dy = y(2) - y(1);

    %Volume
    volume_for_each_coord = dx * dy * depth;

    %Total Volume
    total = sum(volume_for_each_coord, "all");

    %Change to millions of cubic meters
    volume = total / 10^6;
end
