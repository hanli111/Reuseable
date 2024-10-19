function tumor_coords = rowcol_pairs(patient_data)

    tumor_coords = struct('rows', [], 'cols', []);
    for i = 1:length(patient_data)
        image = patient_data{i};
        threshold_image = image > 250;
        [rows, cols] = find(threshold_image);

        tumor_coords(i).rows = rows;
        tumor_coords(i).cols = cols;
    end
end
