% TP 2 - Matlab
% 1
format compact

% 1ABC
x = 0:0.005:10;
y1 = sin(x) - 0.25;
y2 = cos(1-(exp(0.3.*x))./(-3));
plot(x,y1)
hold on
plot(x,y2)
hold off
%find(y1 == y2)
intersect(y1,y2)

%2A
f = 100:5:1000000;
w = 2.*pi.*f;
y1 = 1/6800;
y2 = 2.2e-9.*w.*j;
y3 = 2.2e-9.*w.*j;
y4 = 1/10000;
y5 = 1/22000;
H = -(y1.*y3)./(y2.*y3 + y5.*(y1+y2+y3+y4));
%2BC
subplot(2,1,1);
semilogx(f,20*log10(abs(H)));
grid on
ylabel('|H(j\omega)| (dB)');
title('Bode en Amplitude');
subplot(2,1,2);
semilogx(f,unwrap(angle(H)));
grid on;
xlabel('f');
ylabel('\angleH(j\omega) (rad)');
title('Bode en Phase');

%3A
R1 = 3;
R2 = 10000;
L = 100e-9;
C = 1.5e-9;
f = 100e6 
w = 2.*pi.*f;
Z = R1 + j.*L.*w
Y = (1./R2) + j.*C.*w
Zc = sqrt(Z./Y)
gamma = sqrt(Z.*Y)
alpha = real(gamma)
beta = imag(gamma)
%3B
Zl = 50 + j.*10
gammaL = (Zl - Zc)./(Zl + Zc)
%3C
z = 0:0.01:10;
Vi = 10;
V = abs(Vi).*abs(1 + gammaL.*exp(-2.*gamma.*z)); 
subplot(111);
plot(z,V)
%3D
%TODO

%4AB
x = -pi:pi/30:pi;
y = -pi:pi/30:pi;
[X,Y] = meshgrid(x,y);
Z = (sin(2.*(X.^2)+2.*(Y.^2)))./((X.^2)+(Y.^2));
W = sin(X).*sin((X.^2)+(Y.^2))./((X.^2)+(Y.^2));
subplot(2,2,1);
meshc(X,Y,Z)
subplot(2,2,2);
surf(X,Y,W)
subplot(2,2,3);
%4C
[X,Y,S] = sphere(100);
mesh(X,Y,S)

%5AB
H0 = 1;
E0 = 1;
a = 8e-2;
b = 2e-2;
x = -10:1:10;
y = -10:1:10;
m = 5;
n = 1;
[X,Y] = meshgrid(x,y);
Hz = H0.*cos(m.*pi.*X./a).*cos(n.*pi.*Y./b);
Ez = E0.*sin(m.*pi.*X./a).*sin(n.*pi.*Y./b);
subplot(1,2,1);
surfl(X,Y,Hz)
subplot(122);
meshc(X,Y,Ez)