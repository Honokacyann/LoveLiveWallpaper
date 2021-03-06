Texture2D tex : register(t0);
SamplerState sam : register(s0);

float4 main(float4 pos : SV_POSITION, float2 texCoord : TEXCOORD0, float4 color : COLOR) : SV_TARGET
{
	float4 result = tex.Sample(sam, texCoord);

	result = result * color;

	return result;
}