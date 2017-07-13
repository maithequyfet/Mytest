function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESCENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);


for iter = 1:num_iters

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %
	temp = X * theta;
	K1 = 0;
	K2 = 0;
	%Compute a aternative of cost function J -> K1 and K2
	for i = 1 : m
		K1 = K1 + alpha * 1/ m * (temp(i) - y(i));
		K2 = K2 + alpha * 1/ m * (temp(i) - y(i)) * X(i,2);
	end	
	
	%simultaneously'update
	theta0 = theta(1) - K1;
	theta1 = theta(2) - K2;
	
	theta(1) = theta0;
	theta(2) = theta1;


    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCost(X, y, theta);

end

end
