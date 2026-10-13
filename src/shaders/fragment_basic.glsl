#version 330 core
in vec3 gPos;

out vec4 FragColor;

void main()
{
    FragColor = vec4(gPos.xy,gPos.z + 0.1f, 1.0f);
} 
