//#ifdef DEBUG
//#include "CppUnitTest.h"
//#include "stdafx.h"
//#include "util/vec2.h"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//TEST_CLASS(Vec2Test)
//{
//public:
//	TEST_METHOD(VectorEquality)
//	{
//		vec2 a(1, 1);
//		vec2 b(1, 1);
//		vec2 c(2, 2);
//		Assert::IsTrue(a == b, L"vector equality", LINE_INFO());
//		Assert::IsFalse(a == c, L"vector inequality", LINE_INFO());
//	}
//
//	TEST_METHOD(VectorIsCollideAABB)
//	{
//		Assert::IsTrue(
//			vec2::isCollideAABB(vec2(0, 0), vec2(1, 1), vec2(2, 2), vec2(1, 1)),
//			L"aabb collides", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::isCollideAABB(vec2(0, 0), vec2(0, 1), vec2(1, 1), vec2(1, 1)),
//			L"aabb touches", LINE_INFO()
//		);
//		Assert::IsFalse(
//			vec2::isCollideAABB(vec2(0, 0), vec2(10, 10), vec2(1, 1), vec2(1, 1)),
//			L"aabb does not collide", LINE_INFO()
//		);
//	}
//
//	TEST_METHOD(VectorWillCollideAABB)
//	{
//		// positive cases
//		Assert::IsTrue(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(10, 0),		// points
//				vec2(1, 1), vec2(1, 1),			// sizes
//				vec2(1, 0), vec2(-1, 0)			// velocities
//			) > 0.f,
//			L"aabb will collide, converging horizontal", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(10, 10),		// points
//				vec2(1, 1), vec2(1, 1),			// sizes
//				vec2(1, 1), vec2(-1, -1)		// velocities
//			) > 0.f,
//			L"aabb will collide, converging diagonal", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(0, 10),		// points
//				vec2(1, 1), vec2(1, 1),			// sizes
//				vec2(0, 1), vec2(0, -1)		// velocities
//			) > 0.f,
//			L"aabb will collide, converging vertical", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(10, 0),		// points
//				vec2(1, 1), vec2(1, 1),			// sizes
//				vec2(2, 0), vec2(1, 0)		// velocities
//			) > 0.f,
//			L"aabb will collide, converging horiz same dir", LINE_INFO()
//		);
//
//		// negative cases
//		Assert::IsFalse(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(10, 0),		// points
//				vec2(1, 1), vec2(1, 1),			// sizes
//				vec2(1, 0), vec2(1, 0)			// velocities
//			) > 0.f,
//			L"aabb will not collide, parallel velocity", LINE_INFO()
//		);
//		Assert::IsFalse(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(10, 2),		// points
//				vec2(1, 1), vec2(1, 1),			// sizes
//				vec2(1, 0), vec2(-1, 0)			// velocities
//			) > 0.f,
//			L"aabb will not collide, separating axis", LINE_INFO()
//		);
//		Assert::IsFalse(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(10, 0),		// points
//				vec2(1, 1), vec2(1, 1),			// sizes
//				vec2(-1, 0), vec2(1, 0)			// velocities
//			) > 0.f,
//			L"aabb will collide, diverging horizontal", LINE_INFO()
//		);
//		Assert::IsFalse(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(10, 10),		// points
//				vec2(1, 1), vec2(1, 1),			// sizes
//				vec2(-1, -1), vec2(1, 1)		// velocities
//			) > 0.f,
//			L"aabb will collide, diverging diagonal", LINE_INFO()
//		);
//		Assert::IsFalse(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(0, 10),		// points
//				vec2(1, 1), vec2(1, 1),			// sizes
//				vec2(0, -1), vec2(0, 1)		// velocities
//			) > 0.f,
//			L"aabb will collide, diverging vertical", LINE_INFO()
//		);
//
//		// special cases
//		Assert::AreEqual(
//			vec2::willCollideAABB(
//				vec2(0, 0), vec2(2, 2),			// points
//				vec2(3, 3), vec2(3, 3),			// sizes
//				vec2(-1, -1), vec2(1, 1)		// velocities
//			), 0.f,
//			L"aabb already collided", LINE_INFO()
//		);
//	}
//
//	TEST_METHOD(VectorIsContainAABB)
//	{
//		Assert::IsTrue(
//			vec2::isContainAABB(
//				vec2(0, 0), vec2(0, 0),
//				vec2(1, 1), vec2(1, 1)
//			),
//			L"aabb identical", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::isContainAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(3, 3), vec2(1, 1)
//			),
//			L"aabb fully contained", LINE_INFO()
//		);
//
//		Assert::IsFalse(
//			vec2::isContainAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(1, 1), vec2(1, 1)
//			),
//			L"aabb corner touching", LINE_INFO()
//		);
//		Assert::IsFalse(
//			vec2::isContainAABB(
//				vec2(0, 0), vec2(2, 0),
//				vec2(1, 1), vec2(1, 1)
//			),
//			L"aabb not intersecting", LINE_INFO()
//		);
//		Assert::IsFalse(
//			vec2::isContainAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(2, 2), vec2(2, 2)
//			),
//			L"aabb intersecting, but not contained", LINE_INFO()
//		);
//	}
//	TEST_METHOD(VectorWillExitAABB)
//	{
//		// Positive cases
//		Assert::IsTrue(
//			vec2::willExitAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(3, 3), vec2(1, 1),
//				vec2(0, 0), vec2(1, 1)
//			) > 0.f,
//			L"aabb 1 stationary, aabb 2 moving outside", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willExitAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(3, 3), vec2(1, 1),
//				vec2(-1, -1), vec2(1, 1)
//			) > 0.f,
//			L"aabb moving in opposite directions", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willExitAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(3, 3), vec2(1, 1),
//				vec2(1, 1), vec2(0, 0)
//			) > 0.f,
//			L"aabb 1 moving, aabb 2 stationary", LINE_INFO()
//		);
//
//		// Negative cases
//		Assert::IsTrue(
//			vec2::willExitAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(3, 3), vec2(1, 1),
//				vec2(0, 0), vec2(0, 0)
//			) < 0.f,
//			L"aabb 1 and aabb 2 not moving", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willExitAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(3, 3), vec2(1, 1),
//				vec2(1, 1), vec2(1, 1)
//			) < 0.f,
//			L"aabb 1 and aabb 2 moving, same velocity", LINE_INFO()
//		);
//
//		// Special cases
//		Assert::AreEqual(
//			vec2::willExitAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(1, 1), vec2(1, 1),
//				vec2(1, 1), vec2(1, 1)
//			), 0.f,
//			L"already exited, completely", LINE_INFO()
//		);
//		Assert::AreEqual(
//			vec2::willExitAABB(
//				vec2(0, 0), vec2(1, 1),
//				vec2(2, 2), vec2(2, 2),
//				vec2(1, 1), vec2(1, 1)
//			), 0.f,
//			L"already exited, colliding", LINE_INFO()
//		);
//	}
//
//	TEST_METHOD(VectorWillCollideCircle)
//	{
//		// Positive cases
//		Assert::IsTrue(
//			vec2::willCollideCircle(
//				vec2(0, 0), vec2(3, 0),
//				1, 1,
//				vec2(1, 0), vec2(-1, 0)
//			) > 0,
//			L"two separate circles toward each other", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willCollideCircle(
//				vec2(0, 0), vec2(3, 3),
//				1, 1,
//				vec2(0, 0), vec2(-1, -1)
//			) > 0,
//			L"two separate circles toward each other diag, 1 stationary", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willCollideCircle(
//				vec2(0, 0), vec2(10, 0),
//				1, 1,
//				vec2(3, 0), vec2(1, 0)
//			) > 0,
//			L"two separate circles same dir diff speed", LINE_INFO()
//		);
//		
//		// Negative cases
//		Assert::IsTrue(
//			vec2::willCollideCircle(
//				vec2(0, 0), vec2(3, 0),
//				1, 1,
//				vec2(-1, 0), vec2(1, 0)
//			) < 0,
//			L"two separate circles away from other", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willCollideCircle(
//				vec2(0, 0), vec2(3, 0),
//				1, 1,
//				vec2(0, 0), vec2(1, 0)
//			) < 0,
//			L"two separate circles not moving", LINE_INFO()
//		);
//		Assert::IsTrue(
//			vec2::willCollideCircle(
//				vec2(0, 0), vec2(3, 0),
//				1, 1,
//				vec2(1, 1), vec2(1, 1)
//			) < 0,
//			L"two separate circles moving parallel", LINE_INFO()
//		);
//
//		// Special cases
//		Assert::AreEqual(
//			vec2::willCollideCircle(
//				vec2(0, 0), vec2(3, 0),
//				2, 2,
//				vec2(-1, 0), vec2(1, 0)
//			), 0.0f,
//			L"two collided circles, overlapping", LINE_INFO()
//		);
//		Assert::AreEqual(
//			vec2::willCollideCircle(
//				vec2(0, 0), vec2(0, 0),
//				1, 4,
//				vec2(-1, 0), vec2(1, 0)
//			), 0.0f,
//			L"two collided circles, encased", LINE_INFO()
//		);
//	}
//
//	TEST_METHOD(VectorWillOverlapInterval)
//	{
//		float la = 0, ra = 1, lb = 3, rb = 4;
//		float va = 0, vb = 0;
//		Assert::IsTrue(vec2::willOverlapInterval(la, ra, va, lb, rb, vb) < 0,
//			L"two stationary intervals", LINE_INFO());
//		va = 1, vb = 2;
//		Assert::IsTrue(vec2::willOverlapInterval(la, ra, va, lb, rb, vb) < 0,
//			L"two intervals moving same, too fast", LINE_INFO());
//		va = -1, vb = 1;
//		Assert::IsTrue(vec2::willOverlapInterval(la, ra, va, lb, rb, vb) < 0,
//			L"two intervals moving away", LINE_INFO());
//
//		va = 1, vb = -1;
//		Assert::IsTrue(vec2::willOverlapInterval(la, ra, va, lb, rb, vb) > 0,
//			L"two intervals moving towards", LINE_INFO());
//		va = 2, vb = 1;
//		Assert::IsTrue(vec2::willOverlapInterval(la, ra, va, lb, rb, vb) > 0,
//			L"two intervals moving same, fast enough", LINE_INFO());
//
//		la = 0, ra = 2, lb = 1, rb = 3;
//		Assert::IsTrue(vec2::willOverlapInterval(la, ra, va, lb, rb, vb) == 0,
//			L"already collided", LINE_INFO());
//	}
//
//	TEST_METHOD(VectorWillCollideSAT)
//	{
//		std::vector<vec2> a = {
//			vec2(0,0), vec2(2,0),
//			vec2(0,2), vec2(2,2)
//		};
//		std::vector<vec2> b = {
//			vec2(3,0), vec2(4,1),
//			vec2(6,-1), vec2(5,-2)
//		};
//
//		vec2 va, vb;
//
//		Assert::IsTrue(vec2::willCollideSAT(a, va, b, vb) < 0,
//			L"disjoint, not moving", LINE_INFO());
//		va = vec2(-1, -1), vb = vec2(1, 1);
//		Assert::IsTrue(vec2::willCollideSAT(a, va, b, vb) < 0,
//			L"disjoint, moving perpendicular", LINE_INFO());
//
//		va = vec2(1, 0), vb = vec2(-1, 0);
//		Assert::IsTrue(vec2::willCollideSAT(a, va, b, vb) > 0,
//			L"disjoint, both moving towards", LINE_INFO());
//		va = vec2(1, -1), vb = vec2(-1, 1);
//		Assert::IsTrue(vec2::willCollideSAT(a, va, b, vb) > 0,
//			L"disjoint, both moving towards", LINE_INFO());
//		va = vec2(1, 0), vb = vec2();
//		Assert::IsTrue(vec2::willCollideSAT(a, va, b, vb) > 0,
//			L"disjoint, one moving towards", LINE_INFO());
//	}
//};
//#endif