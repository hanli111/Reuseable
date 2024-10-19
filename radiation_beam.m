function rad_map = radiation_beam(rows,cols,intensity,mri_image)
    %Gets the height and width of the image
    [height, width] = size(mri_image);

    %Makes the radiation map with the height and width of the image all 0's
    rad_map = zeros(height, width);

    %Defines beam intensity
    beam_intensity = intensity;

    %Loops through each row
    for i = 1:length(rows)
        row = rows(i);
        col = cols(i);

        %Checks to see if beam is within the image
        if row > 0 && row <= height && col > 0 && col <= width
            %Draws the beams
            rad_map(row, :) = rad_map(row, :) + beam_intensity;
            rad_map(:, col) = rad_map(:, col) + beam_intensity;
        end
    end
end
