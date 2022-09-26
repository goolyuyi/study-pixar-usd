//
// Created by 于一 on 2022/9/2.
//

#include <iostream>
#include <vector>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdGeom/sphere.h>
#include <pxr/usd/usdGeom/cube.h>
#include <pxr/usd/usdGeom/xformOp.h>
#include <pxr/usd/usdGeom/xformCommonAPI.h>
#include <pxr/usd/usd/primRange.h>

int main() {
    using namespace pxr;
    using namespace std;

    //Stage ops
    const auto stage = UsdStage::CreateNew("tut-1.usda");
    auto xform = UsdGeomXform::Define(stage, SdfPath("/hello"));
    auto sphere = UsdGeomSphere::Define(stage, SdfPath("/hello/sphere"));

    //Prim ops
    cout << "=========GetProperties=============" << endl;
    auto sphere_genericSchema = sphere.GetPrim();
    for (auto i: sphere_genericSchema.GetProperties())
        cout << i.GetName() << endl;

    auto xform_trans_op = xform.AddTranslateOp();
    xform_trans_op.Set(GfVec3d{1,0,0});

    UsdGeomXformCommonAPI(xform).SetScale(GfVec3f{0.5,0.5,0.5});

    stage->SetDefaultPrim(sphere.GetPrim());
    //Attr ops
    auto cube_geomSchema = UsdGeomCube::Define(stage, SdfPath("/hello/cube"));
    auto cube2_genericSchema = stage->DefinePrim(SdfPath("/hello/cube2"), TfToken("cube"));
    auto cube2_geomSchema = UsdGeomCube(cube2_genericSchema);

    auto cube2_displayColor = cube_geomSchema.CreateDisplayColorAttr();
    cube2_displayColor.Set(VtArray<GfVec3f>{{3, 2, 1}});

    //Connect
    auto sphereFromStage = stage->GetPrimAtPath(SdfPath("/hello/sphere"));
    sphereFromStage.CreateRelationship(cube2_displayColor.GetName());
//    auto sphere_color = sphereFromStage.CreateAttribute(vector<string>({"primvars:displayColor"}),
//                                                        cube2_displayColor.GetTypeName());
//    sphere_color.AddConnection(cube2_displayColor.GetPath());

    //Transvers
    cout << "=========Transvers=============" << endl;
    for (UsdPrim i: stage->Traverse()) {
        cout << i.GetPath() << endl;
    }

    stage->GetRootLayer()->Save();
}
