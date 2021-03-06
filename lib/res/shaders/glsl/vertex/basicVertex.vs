attribute vec3 aVertexPosition;
varying vec4 vColor;
uniform float uniformPosition;
uniform mat4 uniformMat;

void main(void)
{
	vColor = vec4(clamp(aVertexPosition, 0.0, uniformPosition), 1.0);
	gl_Position = uniformMat * vec4(0.5 * aVertexPosition, 1.0);
}
