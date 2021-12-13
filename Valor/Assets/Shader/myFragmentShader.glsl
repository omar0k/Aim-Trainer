#version 330 core
	in Vec2 TexCoords;
	uniform sampler2D mypicture;
	out vec4 FragColor;
	void main()
	{
		FragColor=texture(mypicture,TexCoords);
	}