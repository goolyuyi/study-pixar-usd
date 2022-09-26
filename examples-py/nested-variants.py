from pxr import Sdf, Usd

stage = Usd.Stage.CreateNew("nestedVariants.usda")
prim = stage.DefinePrim("/Employee")
title = prim.CreateAttribute("title", Sdf.ValueTypeNames.String)
variantSets = prim.GetVariantSets()

critters = ["Bug", "Bear", "Dragon"]
jobs = ["Squasher", "Rider", "Trainer"]

critterVS = variantSets.AddVariantSet("critterVariant")
for critter in critters:
    critterVS.AddVariant(critter)
    critterVS.SetVariantSelection(critter)
    with critterVS.GetVariantEditContext():
        # All edits now go "inside" the selected critter variant
        jobVS = variantSets.AddVariantSet("jobVariant")
        for job in jobs:
            if (job != "Squasher" or critter == "Bug") and \
                    (job != "Rider" or critter != "Bug"):
                jobVS.AddVariant(job)
                jobVS.SetVariantSelection(job)
                with jobVS.GetVariantEditContext():
                    # Now edits *additionally* go inside the selected job variant
                    title.Set(critter + job)

stage.GetRootLayer().Save()
