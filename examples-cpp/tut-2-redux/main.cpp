//
// Created by 于一 on 2022/9/2.
//


#include <iostream>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdGeom/sphere.h>

#include <pxr/usd/sdf/layer.h>

#include <pxr/usd/sdf/path.h>

int main() {
    using namespace pxr;
    using namespace std;
    const auto stage_1 = UsdStage::Open("tut-1.usda");
    const auto stage_2 = UsdStage::CreateNew("tut-2.usda");

//    auto refSphere = stage_2->OverridePrim(SdfPath("/refSphere"));
//    refSphere.GetReferences().AddReference("./tut-1.usda");


//    auto sphere_from_1 = UsdGeomSphere(stage_1->GetPrimAtPath(SdfPath("/hello/sphere")));
//    auto x = sphere_from_1.GetRadiusAttr();
//    sphere_2.GetPrim().CreateRelationship(x.);
//    stage_2->Save();
}

