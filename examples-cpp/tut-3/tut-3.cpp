//
// Created by 于一 on 2022/9/24.
//

#include <iostream>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/sdf/layer.h>
#include <pxr/usd/sdf/path.h>
#include <pxr/usd/usdGeom/xform.h>

int main(int, char *[]) {
    using namespace pxr;
    using namespace std;

    const auto stage = UsdStage::Open("tut-3.usda");

    const auto sphere = stage->GetPrimAtPath(SdfPath{"/tut3/sphere"});
    const auto cube = stage->GetPrimAtPath(SdfPath{"/tut3/cube"});
    const auto cube2 = stage->GetPrimAtPath(SdfPath{"/tut3/cube2"});

    cout << "=========Play relationship=============" << endl;
    const auto sphere_size = sphere.GetRelationship(TfToken{"cube_rels"});
    SdfPathVector sv{};
    sphere_size.GetTargets(&sv);
    for (const auto &item: sv)
        cout << item << " ";

    cout << "=========Play connection=============" << endl;
    const auto cube_size = cube.GetAttribute(TfToken("size"));
    SdfPathVector sv2{};
    cube_size.GetConnections(&sv2);
    for (const auto &item: sv2)
        cout << item << " ";
    cout << "\n";
    VtValue cube_size_v;
    cube_size.Get(&cube_size_v);
    cout << cube_size_v.Get<double>() << endl;

    const auto cube2_size = cube2.GetAttribute(TfToken("size"));
}
