img = imread('tool15.jpg');

hsv = rgb2hsv(img);
h = hsv(:,:,1);
s = hsv(:,:,2);
v = hsv(:,:,3);

figure
subplot(2,2,1), imshow(hsv);title('HSV');
subplot(2,2,2), imshow(h);title('hue');
subplot(2,2,3), imshow(s);title('saturation');
subplot(2,2,4), imshow(v);title('value');
