//
// Created by 于一 on 2022/9/2.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdGeom/sphere.h>
#include <pxr/usd/usdGeom/cube.h>
#include <pxr/usd/usdGeom/xformOp.h>
#include <pxr/usd/usdGeom/xformCommonAPI.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usdGeom/mesh.h>

int main() {
    using namespace pxr;
    using namespace std;

    const auto stage = UsdStage::CreateNew("tut-1.usda");
    auto xform = UsdGeomXform::Define(stage, SdfPath("/hello"));
    auto sphere = UsdGeomSphere::Define(stage, SdfPath("/hello/sphere"));

    cout << "=========GetProperties=============" << endl;
    auto sphere_genericSchema = sphere.GetPrim();

    cout << setw(40) << left << "GetName()" << setw(20) << "GetNamespace()" << "GetPath()" << endl;
    for (auto i: sphere_genericSchema.GetProperties()) {
        cout << setw(40) << left << i.GetName() << setw(20) << i.GetNamespace()
             << i.GetPath()
             << endl;
    }

    cout << "=========PlayXformOp=============" << endl;
    auto xform_trans_op = xform.AddTranslateOp();
    xform_trans_op.Set(GfVec3d{1, 0, 0});
    UsdGeomXformCommonAPI(xform).SetScale(GfVec3f{0.5, 0.5, 0.5});
    stage->SetDefaultPrim(sphere.GetPrim());

    cout << "=========Play Attribute=============" << endl;
    //Attr ops
    auto cube_geomSchema = UsdGeomCube::Define(stage, SdfPath("/hello/cube"));
    auto cube2_genericSchema = stage->DefinePrim(SdfPath("/hello/cube2"), TfToken("cube"));
    auto cube2_geomSchema = UsdGeomCube(cube2_genericSchema);

    auto cube2_displayColor = cube_geomSchema.CreateDisplayColorAttr();
    cube2_displayColor.Set(VtArray<GfVec3f>{{3, 2, 1}});

    VtDictionary myCustomData{};
    myCustomData.SetValueAtPath("foo", VtValue{5});
    myCustomData.SetValueAtPath("bar", VtValue{"baz"});
    cout << myCustomData << endl;

    cube_geomSchema.GetPrim().SetCustomData(myCustomData);

    cube_geomSchema.CreateSizeAttr(VtValue{2.0});

    cout << "=========Schema=============" << endl;


    //Transvers
    cout << "=========Transvers=============" << endl;
    for (UsdPrim i: stage->Traverse()) {
        cout << i.GetPath() << endl;
    }

    cout << "=========To String=============" << endl;
    auto out = string{};
    stage->ExportToString(&out);
    cout << out << endl;

    stage->GetRootLayer()->Save();
}
