<?php

$log = file('mouse.log');

$im = imagecreatetruecolor(1920, 1080);

$blue = imagecolorallocatealpha($im, 0x00, 0x00, 0xff, 120);
$red = imagecolorallocatealpha($im, 0xff, 0x00, 0x00, 120);

imagefilledrectangle($im, 0, 0, 1920, 1080, 0xffffff);

foreach ($log as $e) {
    list($code, $x, $y) = explode("\t", $e);

    $code = (int)$code;
    $x = (int)$x;
    $y = (int)$y;

    imagefilledellipse($im, $x, $y, 17, 17, $code === 272 ? $red : $blue);
}

imagestring($im, 2, 10, 10, count($log) . ' clicks', 0x000000);

imagepng($im, 'mouse.png');