Shader "Custom/BlackHoleDistortion"
{
    Properties
    {
        _MainTex ("Textura", 2D) = "white" {}
        _DistortionStrength ("Fuerza de Distorsión", Range(0, 1)) = 0.3
        _DistortionRadius ("Radio de Distorsión", Range(0, 1)) = 0.5
        _RotationSpeed ("Velocidad de Rotación", Range(0, 10)) = 2.0
        _EventHorizonSharpness ("Nitidez del Horizonte", Range(1, 20)) = 8.0
        _EventHorizonColor ("Color del Horizonte", Color) = (0.1, 0.4, 1.0, 1.0)
    }
    
    SubShader
    {
        Tags { "RenderType"="Transparent" "Queue"="Transparent" "RenderPipeline"="UniversalPipeline" }
        Blend SrcAlpha OneMinusSrcAlpha
        
        Pass
        {
            HLSLPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "Packages/com.unity.render-pipelines.universal/ShaderLibrary/Core.hlsl"
            
            struct Attributes
            {
                float4 positionOS : POSITION;
                float2 uv : TEXCOORD0;
            };
            
            struct Varyings
            {
                float2 uv : TEXCOORD0;
                float4 positionHCS : SV_POSITION;
            };
            
            TEXTURE2D(_MainTex);
            SAMPLER(sampler_MainTex);
            
            CBUFFER_START(UnityPerMaterial)
                float _DistortionStrength;
                float _DistortionRadius;
                float _RotationSpeed;
                float _EventHorizonSharpness;
                float4 _EventHorizonColor;
            CBUFFER_END
            
            Varyings vert(Attributes IN)
            {
                Varyings OUT;
                OUT.positionHCS = TransformObjectToHClip(IN.positionOS.xyz);
                OUT.uv = IN.uv;
                return OUT;
            }
            
            float2 rotateUV(float2 uv, float rotation, float2 pivot)
            {
                float sinX = sin(rotation);
                float cosX = cos(rotation);
                float2 rotated = float2(
                    cosX * (uv.x - pivot.x) + sinX * (uv.y - pivot.y) + pivot.x,
                    -sinX * (uv.x - pivot.x) + cosX * (uv.y - pivot.y) + pivot.y
                );
                return rotated;
            }
            
            half4 frag(Varyings IN) : SV_Target
            {
                // Calcular distancia al centro
                float2 centeredUV = IN.uv - float2(0.5, 0.5);
                float distanceToCenter = length(centeredUV);
                
                // Normalizar vector dirección
                float2 dir = normalize(centeredUV);
                
                // Rotación basada en tiempo
                float angle = _Time.y * _RotationSpeed;
                float2 rotatedUV = rotateUV(centeredUV, angle, float2(0,0)) + float2(0.5, 0.5);
                
                // Efecto de distorsión
                float distortionFactor = pow(1.0 - saturate(distanceToCenter / _DistortionRadius), _EventHorizonSharpness);
                float2 distortedUV = IN.uv + dir * distortionFactor * _DistortionStrength;
                
                // Muestra la textura con UVs distorsionados
                half4 col = SAMPLE_TEXTURE2D(_MainTex, sampler_MainTex, distortedUV);
                
                // Aplica el color del horizonte de eventos
                float horizonFactor = saturate(pow(1.0 - saturate(distanceToCenter / _DistortionRadius), _EventHorizonSharpness));
                col.rgb += _EventHorizonColor.rgb * horizonFactor;
                
                return col;
            }
            ENDHLSL
        }
    }
}
