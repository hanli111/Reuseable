function water_surface = reservoir_visualization(water_level)
    load('project1_data.mat');
    [X, Y] = meshgrid(x,y);
    water_surface = water_level * ones(size(valley));
    
    water_surface(valley > water_level) = NaN;
    line = -0.8 * X + 2200;
    water_surface(Y < line) = NaN;

    % Open a new MATLAB Figure
    figure;
    % Define the set of colors to be used in this plot
    colormap summer;
    % Plot the valley
    surf(X,Y,valley,EdgeColor="none");
    % Configure the current plot so that new plot commands do not clear it
    hold on;
    % Plot the water and make it blue
    surf(X,Y,water_surface,EdgeColor="none",FaceColor="Blue");
    hold off;

    xlabel('x (m)');
    ylabel('y (m)');
    zlabel('height (m)');
    title('Reservoir Visualization');

    saveas(gcf, 'reservoir visualization');
end
