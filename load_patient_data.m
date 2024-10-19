function [patient_data,num_files] = load_patient_data
    patient_data = {};
    num_files = 0;
    index = 1;

    while true
        filename = "patient" + num2str(index, '%.3d') + "mri.tif";
        if isfile(filename)
            read_files = imread(filename);
            patient_data{end + 1} = read_files;
            index = index + 1;
            num_files = num_files + 1;
        else
            break;
        end
    end
end
