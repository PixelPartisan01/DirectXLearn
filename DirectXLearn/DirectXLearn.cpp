#include <iostream>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <wrl.h>

std::ostream& XM_CALLCONV operator<<(std::ostream& os, DirectX::FXMVECTOR v)
{
	//DirectX::XMFLOAT3 dest;
	//DirectX::XMStoreFloat3(&dest, v);

	//os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	os << "(" << v.m128_f32[0] << ", " << v.m128_f32[1] << ", " << v.m128_f32[2] << ")";
	return os;
}

/// <summary>
/// Calculates the distance between two points represented by XMVECTORs.
/// </summary>
/// <param name="A">The initial point.</param>
/// <param name="B">The terminal point.</param>
/// <returns>The distance between points A and B as an XMVECTOR.</returns>
DirectX::XMVECTOR DistanceBetween2Points(DirectX::XMVECTOR A, DirectX::XMVECTOR B)
{
	return DirectX::XMVector3Length(DirectX::XMVectorSubtract(B, A));
}


int main()
{
	/* Const vectors should use XMVECTORF32 */
	//static const DirectX::XMVECTORF32 g_vHalfVector { 0.5f, 0.5f, 0.5f, 0.5f };

	//static const DirectX::XMVECTORF32 g_vZero { .0f, .0f, .0f, .0f };

	//std::cout << DirectX::XM_PI << std::endl;

	//std::cout << DirectX::XM_1DIVPI << std::endl;

	//DirectX::XMVECTOR nul_vector = DirectX::XMVectorZero();

	//std::cout << nul_vector.m128_i32[0] << "; " 
	//		  << nul_vector.m128_f32[1] << "; " 
	//		  << nul_vector.m128_f32[2] << "; " 
	//		  << nul_vector.m128_f32[3] << "; " << std::endl;

	std::cout.setf(std::ios_base::boolalpha);

	/* Check if SSE2 is suported. */
	if (!DirectX::XMVerifyCPUSupport())
	{
		std::cout << "DirectX Math not supported" << std::endl;
		return -1;
	}

	DirectX::XMVECTOR p = DirectX::XMVectorZero();
	DirectX::XMVECTOR q = DirectX::XMVectorSplatOne();
	DirectX::XMVECTOR u = DirectX::XMVectorSet(1.0f, 2.0f, 3.0f, 4.0f);
	DirectX::XMVECTOR v = DirectX::XMVectorReplicate(-2.0);
	DirectX::XMVECTOR w = DirectX::XMVectorSplatZ(u);

	std::cout << "p = " << p << std::endl;
	std::cout << "q = " << q << std::endl;
	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "w = " << w << std::endl;
	
	std::cout << "XMVector3Length(u): " << DirectX::XMVector3Length(u) << std::endl;
	std::cout << "XMVector3LengthSq(u): " << DirectX::XMVector3LengthSq(u) << std::endl;
	std::cout << "XMVector3Dot(u, v): " << DirectX::XMVector3Dot(u, v) << std::endl;
	std::cout << "XMVector3Cross(u, v): " << DirectX::XMVector3Cross(u, v) << std::endl;
	std::cout << "XMVector3Normalize(u): " << DirectX::XMVector3Normalize(u) << std::endl;
	std::cout << "XMVector3Orthogonal(u): " << DirectX::XMVector3Orthogonal(u) << std::endl;
	std::cout << "XMVector3AngleBetweenVectors(u, v): " << DirectX::XMVector3AngleBetweenVectors(u, v) << std::endl;
	std::cout << "DistanceBetween2Points(A, B): " << DistanceBetween2Points(DirectX::XMVectorSet(1.0f, 2.0f, .0f, .0f), DirectX::XMVectorSet(4.0f, 3.0f, .0f, .0f)) << std::endl;
	std::cout << "XMVector3AngleBetweenVectors(u, v): " << DirectX::XMVector3AngleBetweenVectors(u, v) << std::endl;

	DirectX::XMVECTOR o = DirectX::XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	DirectX::XMVECTOR k = DirectX::XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	DirectX::XMVECTOR projW, perpW;
	DirectX::XMVector3ComponentsFromNormal(&projW, &perpW, o, k);
}