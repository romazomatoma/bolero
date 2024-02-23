#include "BoleroConfig.h"
#include "main_glfw.h"
#include <iostream>

// #include <osgViewer/Viewer>
// #include <osg/Node>
// #include <osg/ShapeDrawable>
// #include <osg/MatrixTransform>

// namespace {
// 	namespace color {
// 		const osg::Vec3 red(1, 0, 0);
// 		const osg::Vec3 green(0, 1, 0);
// 		const osg::Vec3 blue(0, 0, 1);
// 	} // color

// 	osg::Node* Shape(
// 		osg::Shape* shape,
// 		const osg::Vec3& position,
// 		const osg::Vec3& color) {
// 		osg::ShapeDrawable* draw = new osg::ShapeDrawable(shape);
// 		draw->setColor(osg::Vec4(color, 1.0f));
// 		osg::Geode* geo = new osg::Geode();
// 		geo->addDrawable(draw);
// 		osg::MatrixTransform* matTrans = new osg::MatrixTransform();
// 		matTrans->addChild(geo);
// 		matTrans->setMatrix(osg::Matrix::translate(position));
// 		return matTrans;
// 	}

// 	osg::Node* CreateSimpleShape() {
// 		osg::Group* group = new osg::Group();
// 		group->addChild(Shape(new osg::Box(), osg::Vec3(-3, -3, -3), color::red));
// 		group->addChild(Shape(new osg::Sphere(), osg::Vec3(3, 3, 3), color::green));
// 		return group;
// 	}

// 	int ViewerRun(osg::Node* node) {
// 		// �Q�l
// 		// https://takmin.hatenablog.com/entry/20110122/1295706834
// 		osgViewer::Viewer viewer;
// 		viewer.setUpViewInWindow(50, 50, 1280, 720);
// 		viewer.setSceneData(node);

// 		return viewer.run();
// 	}
// } // anonymouse

int main(){
	std::cout << "hello bolero" << std::endl;
	return bolero::MainGlfwLoop();
	// return ViewerRun(CreateSimpleShape());
}