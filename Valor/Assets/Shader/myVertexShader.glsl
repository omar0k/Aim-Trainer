#version 330 core
layout (location=0) in vec aPos;
layout (location=1) in vec2 aTextCoord;

		out vec2 TexCoord;
		void main()
		{
			gl_position=vec4(2*aPos.x/screenSize.x-1,2*aPos.y/screenSize.y-1,0.0,1.0);
			TexCoords=aTexCoord;
		}