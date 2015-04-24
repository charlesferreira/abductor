(function () {
    // class Pixel
    var Pixel = function (x, y) {
        this.value = 255,
        this.fgColor = 15,
        this.bgColor = 7

        this.x = x;
        this.y = y;

        this.isPaintTarget = false;
    };

    // application
    angular.module('generatorApp', ['cfp.hotkeys'])
        .controller('generatorController', function (hotkeys) {
            var generator = this;

            // keyboard shortcuts
            (function () {
                hotkeys.add({
                    combo: 'right',
                    description: 'jumps to pixel to the right',
                    callback: function () {
                        generator.painter.next(0, 1);
                    }
                });
                hotkeys.add({
                    combo: 'left',
                    description: 'jumps to pixel to the left',
                    callback: function () {
                        generator.painter.next(0, -1);
                    }
                });
                hotkeys.add({
                    combo: 'up',
                    description: 'jumps to pixel above',
                    callback: function () {
                        generator.painter.next(-1, 0);
                    }
                });
                hotkeys.add({
                    combo: 'down',
                    description: 'jumps to pixel below',
                    callback: function () {
                        generator.painter.next(1, 0);
                    }
                });
                hotkeys.add({
                    combo: 'k',
                    description: 'sets the pixel transparent',
                    callback: function () {
                        generator.painter.target.bgColor = 13;
                        generator.painter.target.fgColor = 13;
                    }
                });
                hotkeys.add({
                    combo: '0',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 0;
                    }
                });
                hotkeys.add({
                    combo: '1',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 1;
                    }
                });
                hotkeys.add({
                    combo: '2',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 2;
                    }
                });
                hotkeys.add({
                    combo: '3',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 3;
                    }
                });
                hotkeys.add({
                    combo: '4',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 4;
                    }
                });
                hotkeys.add({
                    combo: '5',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 5;
                    }
                });
                hotkeys.add({
                    combo: '6',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 6;
                    }
                });
                hotkeys.add({
                    combo: '7',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 7;
                    }
                });
                hotkeys.add({
                    combo: '8',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 8;
                    }
                });
                hotkeys.add({
                    combo: '9',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 9;
                    }
                });
                hotkeys.add({
                    combo: 'q',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 10;
                    }
                });
                hotkeys.add({
                    combo: 'w',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 11;
                    }
                });
                hotkeys.add({
                    combo: 'e',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 12;
                    }
                });
                hotkeys.add({
                    combo: 'r',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 13;
                    }
                });
                hotkeys.add({
                    combo: 't',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 14;
                    }
                });
                hotkeys.add({
                    combo: 'y',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.bgColor = 15;
                    }
                });
                hotkeys.add({
                    combo: 'shift+0',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 0;
                    }
                });
                hotkeys.add({
                    combo: 'shift+1',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 1;
                    }
                });
                hotkeys.add({
                    combo: 'shift+2',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 2;
                    }
                });
                hotkeys.add({
                    combo: 'shift+3',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 3;
                    }
                });
                hotkeys.add({
                    combo: 'shift+4',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 4;
                    }
                });
                hotkeys.add({
                    combo: 'shift+5',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 5;
                    }
                });
                hotkeys.add({
                    combo: 'shift+6',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 6;
                    }
                });
                hotkeys.add({
                    combo: 'shift+7',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 7;
                    }
                });
                hotkeys.add({
                    combo: 'shift+8',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 8;
                    }
                });
                hotkeys.add({
                    combo: 'shift+9',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 9;
                    }
                });
                hotkeys.add({
                    combo: 'shift+q',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 10;
                    }
                });
                hotkeys.add({
                    combo: 'shift+w',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 11;
                    }
                });
                hotkeys.add({
                    combo: 'shift+e',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 12;
                    }
                });
                hotkeys.add({
                    combo: 'shift+r',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 13;
                    }
                });
                hotkeys.add({
                    combo: 'shift+t',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 14;
                    }
                });
                hotkeys.add({
                    combo: 'shift+y',
                    description: 'paints the pixel',
                    callback: function () {
                        generator.painter.target.fgColor = 15;
                    }
                });
            })();

            // game screen resolution
            generator.screenWidth = 4;
            generator.screenHeight = 4;

            // adjusts the grid according to screen resolution
            (generator.updateGrid = function () {
                generator.sprite = "";
                generator.grid = [];

                for (var i = 0; i < (generator.screenHeight || 1); i++) {
                    generator.grid[i] = [];
                    for (var j = 0; j < (generator.screenWidth || 1); j++) {
                        generator.grid[i][j] = new Pixel(i, j);
                    }
                }
            })();
            
            // generates hexadecimal code for the sprite
            generator.compile = function () {
                generator.sprite = "";
                for (var i = 0; i < generator.screenHeight; i++)
                {
                    for (var j = 0; j < generator.screenWidth; j++)
                    {
                        var pixel = generator.grid[i][j];

                        // appends hexadecimal pixel value
                        var value = parseInt(pixel.value).toString(16);
                        while (value.length < 2) value = '0' + value;
                        generator.sprite += value;


                        // calculates and appends pixel hexadecimal color
                        var fgColor = parseInt(pixel.fgColor) << 4;
                        var bgColor = parseInt(pixel.bgColor);

                        var hex = (fgColor + bgColor).toString(16);
                        while (hex.length < 2) hex = '0'+ hex;
                        generator.sprite += hex;
                    }
                    generator.sprite += '\n';
                }
                document.getElementById('compiled-sprite').value = generator.sprite;
            };

            // generates grid from hexadecimal sprite code
            generator.import = function () {
                var textarea = document.getElementById('compiled-sprite');
                var sprite = textarea.value.trim().split('\n');

                console.log(sprite);

                var width = sprite[0].length;
                var height = sprite.length;

                console.log(width + ' x ' + height)

                generator.screenWidth = width / 4;
                generator.screenHeight = height;
                generator.updateGrid();

                for (var i = 0; i < height; i++) {
                    for (var j = 0; j < width/4; j++) {
                        // gets pixel value
                        var pos = j * 4;
                        var value = parseInt(sprite[i].substring(pos, pos + 2), 16);
                        var fgColor = parseInt(sprite[i].substring(pos + 2, pos + 3), 16);
                        var bgColor = parseInt(sprite[i].substring(pos + 3, pos + 4), 16);

                        var pixel = new Pixel(i, j);
                        pixel.value = value;
                        pixel.fgColor = fgColor;
                        pixel.bgColor = bgColor;

                        generator.grid[i][j] = pixel;
                    }
                }
            };

            // facilitates the process of painting pixels
            generator.painter = {
                x: 0,
                y: 0,
                pixel: new Pixel(),
                paint: function () {
                    var x = generator.painter.x = parseInt(generator.painter.x);
                    var y = generator.painter.y = parseInt(generator.painter.y);

                    if (generator.grid[y] && generator.grid[y][x]) {
                        var pixel = generator.grid[y][x];
                        var tint = generator.painter.pixel;

                        pixel.value = tint.value;
                        pixel.fgColor = tint.fgColor;
                        pixel.bgColor = tint.bgColor;

                        var stepCol = 0;
                        if (x == generator.screenWidth - 1)
                            stepCol = 1;
                        generator.painter.next(stepCol, 1);
                    }
                },
                paintAll: function() {
                    var tint = generator.painter.pixel;

                    for (var j = 0; j < generator.screenWidth; j++) {
                        for (var i = 0; i < generator.screenHeight; i++) {
                            var pixel = generator.grid[i][j];
                            pixel.value = tint.value;
                            pixel.fgColor = tint.fgColor;
                            pixel.bgColor = tint.bgColor;
                        }
                    }
                },
                next: function (stepRow, stepCol) {
                    generator.painter.y += stepRow;
                    generator.painter.x += stepCol;

                    // keeps the boundaries
                    if (generator.painter.x >= generator.screenWidth) {
                        generator.painter.x = 0;
                    }
                    else if (generator.painter.x < 0) {
                        generator.painter.x = generator.screenWidth - 1;
                    }

                    if (generator.painter.y >= generator.screenHeight) {
                        generator.painter.y = 0;
                    }
                    else if (generator.painter.y < 0) {
                        generator.painter.y = generator.screenHeight - 1;
                    }

                    generator.setPaintTarget();

                },
                target: generator.grid[0][0]
            }

            // marks the current pixel for painting
            generator.setPaintTarget = function (pixel) {
                if (pixel) {
                    generator.painter.x = pixel.y;
                    generator.painter.y = pixel.x;
                }

                // unsets previous target
                if (generator.painter.target instanceof Pixel)
                    generator.painter.target.isPaintTarget = false;

                // sets current target
                if (generator.grid[generator.painter.y] && generator.grid[generator.painter.y][generator.painter.x]) {
                    generator.painter.target = generator.grid[generator.painter.y][generator.painter.x];
                    generator.painter.target.isPaintTarget = true;
                }
            };

            generator.setPaintTarget();
        })

        // updates pixel's relative textarea to reflect it's attributes
        .directive('pixelContainer', function () {
            return function (scope, element) {
                element.bind('keyup', function () {
                    var val = element[0].value.split('\n');
                    var pixel = element.parent().scope().pixel || element.parent().scope().generator.painter.pixel

                    if (val.length != 3 || val[0] == '' || val[1] == '' || val[2] == '') {
                        console.log(val);
                        pixel = new Pixel();
                    } else {
                        console.log(val);
                        pixel.value = val[0];
                        pixel.fgColor = val[1];
                        pixel.bgColor = val[2];
                    }
                    element.parent().scope().$apply();
                });
            };
        });
})();