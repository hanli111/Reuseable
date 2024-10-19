function [tumor_dose,total_dose] = dose_plan(patient_data)
    tumor_dose = 0;
    total_dose = 0;

    %Gives the coordinates of the tumor
    tumor_coords = rowcol_pairs(patient_data);
    
    for i = 1:length(patient_data)
        image = patient_data{i};

        %Gives the row and col # of the tumor
        rows = tumor_coords(i).rows;
        cols = tumor_coords(i).cols;

        %Defines the beam intensity
        beam_intensity = 0.5*10^-8;

        %Makes the radiation map
        rad_map = radiation_beam(rows, cols, beam_intensity, image);

        %Sum up total dose and convert to units of milliGray
        total_dose(i) = sum(rad_map(:)) * 1000;

        %Defining the tumor threshold
        threshold = 250;
        tumor_threshold = image > threshold;

        %Sum up tumor dose and convert to units of milliGray
        tumor_dose(i) = sum(rad_map(tumor_threshold)) * 1000;
    end
end
