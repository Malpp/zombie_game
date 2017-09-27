#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ZombieUnitTest
{

	//static sf::Texture test_texture;

	/*class TestObject : public Collidable
	{
	public:
		TestObject(sf::Vector2f& pos, float collide_size_radius)
			: Collidable(pos, 0, &test_texture, collide_size_radius)
		{
		}

	protected:
		void handleCollision(Collidable* entity) override
		{
		};
	};*/

	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(NoCollision)
		{
			/*TestObject test1(sf::Vector2f(0,0),10);
			TestObject test2( sf::Vector2f(0,30), 10 );
			Assert::IsFalse( test1.checkCollision( &test2 ) );*/
		}

		TEST_METHOD(Collision)
		{
			/*TestObject test1(sf::Vector2f(0, 0), 10);
			TestObject test2(sf::Vector2f(0, 10), 10);
			Assert::IsTrue(test1.checkCollision(&test2));*/
		}

		TEST_METHOD(EdgeCaseNoCollision)
		{
			/*TestObject test1(sf::Vector2f(0, 0), 10);
			TestObject test2(sf::Vector2f(0, 20), 10);
			Assert::IsFalse(test1.checkCollision(&test2));*/
		}

		TEST_METHOD(EdgeCaseCollision)
		{
			/*TestObject test1(sf::Vector2f(0, 0), 10);
			TestObject test2(sf::Vector2f(0, 19.999f), 10);
			Assert::IsTrue(test1.checkCollision(&test2));*/
		}
	};
}