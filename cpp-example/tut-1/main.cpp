//
// Created by 于一 on 2022/9/2.
//

#include <iostream>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdGeom/sphere.h>

int main() {
    using namespace pxr;
    using namespace std;
    const auto stage = UsdStage::CreateNew("HelloWorld.usda");
    auto xformPrim = UsdGeomXform::Define(stage, SdfPath("/hello"));
    auto spherePrim = UsdGeomSphere::Define(stage, SdfPath("/hello/world"));

    auto genericPrim = spherePrim.GetPrim();
    for (auto i: genericPrim.GetProperties()) {
        cout << i.GetName() << ' ';
    }
    cout << endl;
    for (auto i: genericPrim.GetRelationships()) {
        cout << i.GetName() << ' ';
    }
    cout << endl;
    for (auto i: genericPrim.GetAttributes()) {
        cout << i.GetName() << ' ';
    }

    stage->GetRootLayer()->Save();
}
