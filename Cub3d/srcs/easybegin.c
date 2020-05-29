function player(x, y, direction)
{
  this.x = x;
  this.y = y;
  this.direction = direction;
}

function map(size)
{
this.size = size;
this.wall = new Uint8Array(size * size);
}

var x = column / this.resolution - 0.5;
var angle = Math.atan2(x, this.focalLength);
var ray = map.cast(player, player.direction + angle, this.range);

function ray(origin)
{
  var stepX = step(sin, cos, origin.x, origin.y);
  var stepY = step(cos, sin, origin.y, origin.x, true);
  var nextStep = stepX.length2 < stepY.length2
    ? inspect(stepX, 1, 0, origin.distance, stepX.y)
    : inspect(stepY, 0, 1, origin.distance, stepY.x);
  if (nextStep.distance > range) return [origin];
    return [origin].concat(ray(nextStep));
}

var dx = run > 0 ? Math.floor(x + 1) - x : Math.ceil(x - 1) - x;
var dy = dx * (rise / run);

var z = distance * Math.cos(angle);
var wallHeight = this.height * height / z;

Camera.prototype.render = function(player, map)
{
  this.drawSky(player.direction, map.skybox, map.light);
  this.drawColumns(player, map);
  this.drawWeapon(player.weapon, player.paces);
};

loop.start(function frame(seconds)
{
  map.update(seconds);
  player.update(controls.states, map, seconds);
  camera.render(player, map);
});

var rainDrops = Math.pow(Math.random(), 3) * s;
var rain = (rainDrops > 0) && this.project(0.1, angle, step.distance);

ctx.fillStyle = '#ffffff';
ctx.globalAlpha = 0.15;
while (--rainDrops > 0) ctx.fillRect(left, Math.random() * rain.top, 1, rain.height);

ctx.fillStyle = '#000000';
ctx.globalAlpha = Math.max((step.distance + step.shading) / this.lightRange - map.light, 0);
ctx.fillRect(left, wall.top, width, wall.height);

Player.prototype.walk = function(distance, map)
{
  var dx = Math.cos(this.direction) * distance;
  var dy = Math.sin(this.direction) * distance;
  if (map.get(this.x + dx, this.y) <= 0) this.x += dx;
  if (map.get(this.x, this.y + dy) <= 0) this.y += dy;
};

step.offset = offset - Math.floor(offset);
var textureX = Math.floor(texture.width * step.offset);
