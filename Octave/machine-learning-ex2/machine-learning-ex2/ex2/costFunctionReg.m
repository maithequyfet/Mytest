function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta

%Compute the total extremely values
SumOfTheta = 0;
for i = 2:size(theta)
	SumOfTheta = SumOfTheta + lambda / (2 * m) * (theta(i))^2;
end	

%Call costFunction have been implemmented to get cost(value of
% cost function) and gradient decent vector
[cost,gradient] = costFunction(theta, X , y);

J = cost + SumOfTheta;

K = (size(theta));
% Calculate grad base on gradient have been compute before
for i = 1:size(theta)
	if i == 1
		K(1) = gradient(1);
	else	
		K(i) = gradient(i) + lambda/m * theta(i);
end
grad = K;


% =============================================================

end
