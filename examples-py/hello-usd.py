from pxr import Usd, UsdGeom

stage = Usd.Stage.CreateNew('./usd/HelloWorld.usda')
xformPrim = UsdGeom.Xform.Define(stage, '/hello')
spherePrim = UsdGeom.Sphere.Define(stage, '/hello/world')
stage.GetRootLayer().Save()
