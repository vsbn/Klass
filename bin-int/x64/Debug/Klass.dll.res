        ��  ��                  j       ������    0 	        #version 460 core

layout(location = 0) in vec4 position;

void main()
{
	gl_Position = position;
}  t       ������    0 	        #version 460 core

layout(location = 0) out vec4 colour;

void main()
{
	colour = vec4(1.0, 0.0, 1.0, 1.0);
}