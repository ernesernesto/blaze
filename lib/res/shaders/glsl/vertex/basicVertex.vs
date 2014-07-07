attribute vec3 aVertexPosition;
varying vec4 vColor;

void main(void)
{
	vColor = vec4(clamp(aVertexPosition, 0.0, 1.0), 1.0);
	gl_Position = vec4(0.5 * aVertexPosition, 1.0);
}
